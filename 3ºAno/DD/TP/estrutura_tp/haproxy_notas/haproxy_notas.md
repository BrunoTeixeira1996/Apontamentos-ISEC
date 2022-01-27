# HAProxy Notas

- Instalar

```code
sudo apt install haproxy
```

## Ficheiro de configuração 

```code
ls -la /etc/haproxy/haproxy.cfg
```

- O HAProxy funciona em dois modos diferentes, HTTP ou TCP
  - Quando opera em TCP dizemos que é um Proxy de camada 4 (OSI)
	- Quando o HAProxy opera neste modo, o mesmo apenas tem acesso a qual IP e Porto o cliente está a tentar aceder, não conseguindo assim ver a informação de ambas as partes.
  - Quando opera em HTPP dizemos que é um Proxy de camada 7 (OSI)
	- Quando o HAProxy opera neste modo, o mesmo tem acesso a tudo, logo estamos a confiar toda a nossa informação ao nosso proxy uma vez que o mesmo tem de ver a informação que transita de lado para lado.
	
- Existem 4 secções no ficheiro de configuração do HAProxy.
  - `global`
  - `defaults`
  - `frontend`
  - `backend`

-  Estas secções definem como é que o servidor se comporta, quais são as definições por omissão e como é que o cliente faz pedidos e recebe as respostas


### global

- Nesta primeira secção estão definidas as medidas em que o processo vai operar, sendo estas medidas de um nível mais baixo, ou seja, relacionadas com o sistema operativo.

- O comando `stats socket` ativa a API do HAProxy sendo assim possível gerar um *endpoint* com todas as estatisticas do proxy e dos servidores web

### defaults

- Esta secção não é obrigatória, no entanto permite reduzir a duplicação, uma vez que as configurações feitas aqui são aplicadas na secção `frontend` e `backend`

- Neste caso usamos o modo `http`

### listen

- Aqui podemos combinar o **frontend** e o **backend** ao mesmo tempo. Isto é útil pois é aqui feito o redirecionamento para o *endpoint* de estatisticas

- Falar que o auth devia de ser com encriptação


### frontend

- Nesta secção definimos como é que os pedidos dos utilizadores irão ser encaminhados para o *backend*


- `http-in` é apenas um nome para o frontend
- fazemos *bind* ao IP do servidor de HAProxy:Porto
- qualquer pessoa que se conecte a este servidor irá ser redirecionado para os *webservers* e fazemos isso usando `default_backend <nome do backend>`


### backend

- Aqui definimos os *webservers* que irão operar na nossa infraestrutura, definindo tambem o algoritmo de *load balancing* a ser utilizado

- damos o nome ao backend, tem de ser o mesmo nome que demos no `default_backend` no **frontend**

- No campo `balance` escolhemos o algoritmo que quisermos utilizador na atribuição de webservers aos clientes, sendo que dois deles são os mais interessantes:
  - roundrobin -> cada servidor é usado por turnos, um de cada vez
  - leastcoon -> o servidor com o numero mais baixo de conexões é o escolhido

- No final estamos a fazer um `check` com um intervalo de 500 milisegundos, se falhar 3 vezes retira esse webserver do grupo.

# References

- https://www.haproxy.com/blog/the-four-essential-sections-of-an-haproxy-configuration/

- https://medium.com/@endersonjackson2/load-balancing-com-haproxy-e-tomcat-294b4bad43ed
