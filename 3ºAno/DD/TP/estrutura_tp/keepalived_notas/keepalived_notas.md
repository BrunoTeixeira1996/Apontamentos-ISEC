# KeepAlived Notas

- Instalar

```code
sudo apt install keepalived
```

## Ficheiro de configuração 

```code
nano /etc/keepalived/keepalived.conf
```

- Ter atenção que se quiser mexer no ficheiro de config do haproxy tenho de fazer `sudo service haproxy reload`
- Ter atenção que tenho de começar o keepalived primeiro e só depois o haproxy se nao o haproxy nao conhece o ip 192.168.1.200

![image](https://user-images.githubusercontent.com/12052283/143155328-4d9434c1-b873-4ca3-844f-9a0400bf0664.png)

- Para trocar do haproxy01 para o haproxy02 tenho de desligar o haproxy no haproxy01
- Se quiser voltar a ter o haproxy01 como MASTER tenho de desligar o haproxy e o keepalived no haproxy02

- Isto é um problema porque apenas devia de desligar o haproxy, no entanto ao ligar o haproxy no servidor que está como BACKUP o mesmo nao vê o ip 192.168.1.200 entao nao liga.
  - Posso tentar colocar uma entrada estática com o ip 192.168.1.200
- RESOLVIDO USANDO ISTO https://www.cyberciti.biz/faq/linux-bind-ip-that-doesnt-exist-with-net-ipv4-ip_nonlocal_bind/
-------------------------------------------------------------------------------------------------------------------------

- No ficheiro de configuração do Keepalived foi criado um vrrp_script com o intuito de verificar, com um intervalo de 2 em 2 milisegundos, se o haproxy está a funcionar corretamente. Se o mesmo não estiver a funcionar, o peso dele diminui em 10 reduzindo assim a sua prioridade fazendo com que o BACKUP apasse a ser MASTER.

- Depois foi criado um vrrp_instance que define uma instância individual do protocolo VRRP com alguns atributos

- **global_defs**
  - Define que utilizador pode executar scripts

- **interface**
  - Refere-se à interface que estamos a monitorizar

- **state**
  - É aqui que dizemos o estado inicial da instância, ou seja, se o servidor é o MASTER ou o BACKUP

- **virtual_router_id**
  - É uma identificação entre os dois servidores HAProxy e ambos os seridores têm de ter o mesmo *virtual_router_id*
  
- **priority**
  - Aqui é a prioridade que o servidor vai anunciar para o grupo VRRP, sendo que a prioridade mais alta pertence ao MASTER
- **virtual_ipaddress**
  - Qual é o ip virtual que os cliente se vão conectar

- **track_script**
  - Invocamos o script

- MOstrar que tive de mudar a configuração no HAProxy e colocar o ip 192.168.1.200 em vez dos IPs dos servidores

# References

- https://www.redhat.com/sysadmin/keepalived-basics

- https://www.redhat.com/sysadmin/advanced-keepalived

- https://www.youtube.com/watch?v=o2zGUnL3tP8
