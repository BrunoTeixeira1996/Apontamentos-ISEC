# Experiência 03

- Fazer isto antes de ligar as bases de dados  https://maslosoft.com/blog/2020/07/28/how-to-gracefully-reboot-mariadb-galera-cluster-servers/

## How To

### Configurar servidor de mariadb com o Galera Cluster

- No primeiro servidor de base de dados criei um ficheiro em `/etc/mysql/mariadb.conf.d/galera.cnf`

```bash
[mysqld] 
bind-address=0.0.0.0 
default_storage_engine=InnoDB 
binlog_format=row 
innodb_autoinc_lock_mode=2  # Galera cluster configuration 
wsrep_on=ON 
wsrep_provider=/usr/lib/galera/libgalera_smm.so
wsrep_cluster_address="gcomm://192.168.1.182,192.168.1.186"
wsrep_cluster_name="mariadb-galera-cluster" 
wsrep_sst_method=rsync  # Cluster node configuration 
wsrep_node_address="192.168.1.182" 
wsrep_node_name="galera-db-01"
```

- No segundo servidor de base de dados criei um ficheiro em `/etc/mysql/mariadb.conf.d/galera.cnf`


```bash
[mysqld] 
bind-address=0.0.0.0 
default_storage_engine=InnoDB 
binlog_format=row 
innodb_autoinc_lock_mode=2  # Galera cluster configuration 
wsrep_on=ON 
wsrep_provider=/usr/lib/galera/libgalera_smm.so
wsrep_cluster_address="gcomm://192.168.1.182,192.168.1.186"
wsrep_cluster_name="mariadb-galera-cluster" 
wsrep_sst_method=rsync  # Cluster node configuration 
wsrep_node_address="192.168.1.186" 
wsrep_node_name="galera-db-01"
```

- Depois disto já temos o cluster com replicação entre os dois servidores de base de dados, ou seja, sempre que é feita uma query de alteração numa base de dados, a outra recebe a mesma query e executa-a

- Para vermos quantos nodes existem no Galera cluster fazemos `sudo mysql -u root -p -e "show status like 'wsrep_cluster_size'"`

### Configurar o novo HAProxy para ser um loadbalancer para os dois servidores de base de dados

- Editei o ficheiro de configuraçã do HAProxy que está em `/etc/haproxy/haproxy.cfg`

```bash
frontend mariadb_cluster_frontend
    bind *:3306
    mode tcp
    option tcplog
    default_backend galera_cluster_backend

backend galera_cluster_backend
    mode tcp
    option tcpka
    balance leastconn
    server mysql-01 192.168.1.182:3306  check weight 1
    server mysql-02 192.168.1.186:3306  check weight 1
```

### Configurar o novo SQLALCHEMY_URI da aplicação Web para apontar para o HAProxy

- Indo a `/etc/environment` está lá definida a variavel de ambiente `DB_HOST` e neste caso foi preciso alterar o IP de `192.168.1.182` para o IP do HAProxy que agora é `192.168.1.185`

## Resultado

- Foi feita uma caputa no HAProxy03 (192.168.1.185) usando o wireshark
- Depois foi então feito o login na aplicação web
- Com a captura é percetivel o que acontece
  - A primeira vez o servidor web 192.168.1.181 emite um ARP para saber qual é o MAC address do 192.168.1.185(HAProxy)
  - Depois o HAProxy transmite o seu ARP
  - Depois existe uma saudação (`Server Greeting`) entre a base de dados que neste caso foi a 192.168.1.182 e o HAProxy emitindo tambem esta saudação do HAProxy para o servidor web 192.168.1.181
  - De seguida ha um Login Request e é percetivel que o trafego agora circula sempre entre servidor web <-> HAproxy <-> Galera Cluster (bd01 & bd02)
  
  - Depois foi atualizad a página do carrinho e mais uma vez existe a comunicação entre servidor web <-> HAproxy <-> Galera Cluster (bd01 & bd02), sendo que o servidor web faz a SQL Query ao HAProxy e o mesmo encaminha
  - Seguindo o pacote SQL, é visto então a query em SQL feita do servidor web para a base de dados
  

## Falha com esta experiência

- Continua a haver um SPOF mas agora no haproxy que se adicionou. Não existe redundância aqui 


## Referências

- https://medium.com/platformer-blog/highly-available-mysql-with-galera-and-haproxy-e9b55b839fe0

- https://stackoverflow.com/questions/49283298/read-read-write-uris-for-amazon-web-services-rds

- https://ubuntuforums.org/showthread.php?t=2441797
