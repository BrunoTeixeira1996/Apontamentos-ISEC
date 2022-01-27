from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, SubmitField, BooleanField, IntegerField
from wtforms.validators import DataRequired, Length, Email, EqualTo


class LoginForm(FlaskForm):
    email = StringField('Email',validators=[DataRequired(), Email()])
    password = PasswordField('Password', validators=[DataRequired()])
    submit = SubmitField('Login')

class ProductForm(FlaskForm):
	product_type = StringField("Tipo", validators=[DataRequired()])
	quantity = IntegerField("Quantidade", validators=[DataRequired()])
	local = StringField("Local de Compra", validators=[DataRequired()])
	submit = SubmitField('Inserir')
