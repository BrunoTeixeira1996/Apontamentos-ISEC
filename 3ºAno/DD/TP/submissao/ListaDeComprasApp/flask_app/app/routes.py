from flask import render_template, flash, redirect, url_for, request, jsonify, make_response
from app import app,db
from app.forms import LoginForm, ProductForm
from flask_login import current_user, login_user, logout_user, login_required
from app.models import Clientes, Compras


# index
@app.route("/")
def index():
    return render_template("index.html")

# login
@app.route('/login', methods=['GET', 'POST'])
def login():
	if current_user.is_authenticated:
		return redirect(url_for("carrinho"))

	form = LoginForm()
	if form.validate_on_submit():
		# query à bd
		user = Clientes.query.filter_by(email=form.email.data).first()
		# verifica o resultado da query, se nao existir ...
		if user is None: #or not user.check_password(form.password.data):
			flash("Login invalido","danger")
			return redirect(url_for("login"))
		# se existir faz login
		else:
			login_user(user)
		return redirect(url_for("carrinho"))
	return render_template("login.html", title="Login", form=form)

# logout
@app.route("/logout")
def logout():
	logout_user()
	flash("Logout com sucesso", "info")
	return redirect(url_for("index"))


# carrinho
@app.route("/carrinho/", methods=["GET", "POST"])
@login_required
def carrinho():
	# lista produtos atuais do cliente
	customer_list = db.session.query(Compras.id_compras.label("id_compras"),
					Compras.tipo.label("Tipo"),
					Compras.quantidade.label("Quantidade"),
					Compras.local.label("Local"))\
					.join(Clientes, Compras.id_cliente == Clientes.id_cliente)\
					.filter(Compras.id_cliente==current_user.get_id()).all()

    # adicionar produtos ao carrinho
	form = ProductForm()
	if form.validate_on_submit():
		compras = Compras(tipo = form.product_type.data,
				quantidade = form.quantity.data,
				local = form.local.data,
				id_cliente = current_user.get_id())
		db.session.add(compras)
		db.session.commit()

		return redirect(url_for("carrinho"))
		
	return render_template("carrinho.html", title="Lista", form=form, customer_list=customer_list)

# apagar artigo
@app.route("/apagar_artigo",methods=["POST"])
@login_required
def delete_item():
	# recebe o POST feito no js
	req = request.get_json()
	# aplica a query
	Compras.query.filter_by(id_compras=int(req["id"])).delete()
	db.session.commit()

	return redirect(url_for("carrinho"))
