## IPs dos webservers

- `webserver01 192.168.1.180`
- `webserver02 192.168.1.181`

## IPs dos HAProxys 

- `haproxy01 192.168.1.183`
- `haproxy02 192.168.1.184`

## IP da BD

- `db 192.168.1.182`

- root:toor
- brun0:toor

### Esquema da BD

```sql
create table clientes(
    id_cliente int auto_increment,
    nome varchar(255) not null,
    email varchar(255) not null,
    password varchar(255) not null,
    primary key(id_cliente)
);


create table compras(
    id_compras int auto_increment,
    id_cliente int,
    tipo varchar(255) not null,
    quantidade int not null,
    local varchar(255) not null,
    primary key(id_compras),
    foreign key(id_cliente)
    references clientes(id_cliente)
);

```

- Inserir dados dos clientes

```sql
insert into clientes(nome, email,password) values ("Bruno", "a2019100036@isec.pt", "passwordsegura");
insert into clientes(nome, email,password) values ("Bruna", "bruna@bruna.pt", "passwordsegura");
```

- Inserir dados nas compras

```sql
insert into compras(id_cliente,tipo,quantidade,local) values (1, "Laranjas", 5,"PingoDoce");
insert into compras(id_cliente,tipo,quantidade,local) values (1, "Maças", 2,"PingoDoce");
insert into compras(id_cliente,tipo,quantidade,local) values (1, "Peras", 3,"PingoDoce");
insert into compras(id_cliente,tipo,quantidade,local) values (2, "Aboboras", 2,"Lidl");
insert into compras(id_cliente,tipo,quantidade,local) values (2, "Barritas de Chocolate", 3,"Lidl");
```

- Pegar em todos os artigos dos carrinhos do cliente 1

```sql
select compras.id_compras "Id Compras", compras.id_cliente "Id Cliente", clientes.nome "Nome Cliente", compras.tipo, compras.quantidade, compras.local from compras inner join clientes on compras.id_cliente = clientes.id_cliente and clientes.id_cliente = 1;
```

- Deu erro ao tentar conectar externamente com a DB entao fiz o que diz aqui https://stackoverflow.com/questions/64320136/error-2002-hy000-cant-connect-to-mysql-server-on-192-168-1-15-115

- Depois tive de dar permissões ao user para aceder remotamente e usei isto:

```sql
mysql -u root -p
GRANT ALL ON *.* to brun0@'192.168.1.180' IDENTIFIED BY 'toor';
GRANT ALL ON *.* to brun0@'192.168.1.181' IDENTIFIED BY 'toor';
FLUSH PRIVILEGES;
exit
sudo service mariadb restart
```


# Recursos

- https://www.youtube.com/watch?v=o2zGUnL3tP8
- https://pplware.sapo.pt/tutoriais/tutorial-balanceamento-de-carga-em-servidores-com-haproxy/
- https://www.digitalocean.com/community/tutorials/an-introduction-to-haproxy-and-load-balancing-concepts
- https://www.youtube.com/watch?v=IgP201jxFdc
- https://stackoverflow.com/questions/13271484/postgresql-connect-remote-server-to-host-database-with-python
- https://towardsdatascience.com/python-and-postgresql-how-to-access-a-postgresql-database-like-a-data-scientist-b5a9c5a0ea43

- https://www.slidescarnival.com/ -> para a apresentação
- https://romannurik.github.io/SlidesCodeHighlighter/ -> para a apresentação
