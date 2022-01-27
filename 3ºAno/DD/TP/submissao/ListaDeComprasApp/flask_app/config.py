import os

basedir = os.path.abspath(os.path.dirname(__file__))

class Config(object):
	SECRET_KEY = "something"
	SQLALCHEMY_DATABASE_URI = os.environ.get('DB_HOST')
	SQLALCHEMY_TRACK_MODIFICATIONS = False
