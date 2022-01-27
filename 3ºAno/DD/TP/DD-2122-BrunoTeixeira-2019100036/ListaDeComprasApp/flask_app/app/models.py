from app import db, login
from werkzeug.security import generate_password_hash, check_password_hash
from flask_login import UserMixin

@login.user_loader
def load_user(id):
    return Clientes.query.get(int(id))

class Clientes(UserMixin, db.Model):
	id_cliente = db.Column(db.Integer, primary_key=True)
	nome = db.Column(db.String(64), index=True, unique=True)
	email = db.Column(db.String(120), index=True, unique=True)
	password = db.Column(db.String(128))
	compras = db.relationship("Compras", backref="cliente")
	"""
	def __repr__(self):
		return f"{self.nome}"

	def set_password(self, password):
		self.password = generate_password_hash(password)

	def check_password(self, password):
		return check_password_hash(self.password,password)
"""
	def get_id(self):
		return self.id_cliente

class Compras(db.Model):
	id_compras = (db.Column(db.Integer, primary_key=True))
	tipo = db.Column(db.String(140))
	quantidade = db.Column(db.Integer)
	local = db.Column(db.String(140))
	id_cliente =  db.Column(db.Integer, db.ForeignKey("clientes.id_cliente"))

	def __repr__(self):
		return f"{self.id_compras}"
