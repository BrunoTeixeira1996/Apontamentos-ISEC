# Experiência 01

- Ligou-se o webserver01
- Ligou-se o webserver02

- Fez-se uma captura no haproxy para perceber o que acontecia com o tráfego

## Resultado

- O cliente (`192.168.1.123`) envia um HTTP GET Request diretamente ao Servidor HAProxy (`192.168.1.183`)
- De seguida o Servidor HAProxy vai fazer um HTTP GET Request ao Webserver disponivel, que neste caso foi o webserver01 (`192.168.1.180`)
- O webserver01 responde com o HTTP status code 200, mostrando que a comunicação ocorreu sem falhas, e o HAProxy redireciona essa resposta para o cliente
- De seguida foi feito outro pedido pelo mesmo cliente, no entanto consegue-se perceber que neste caso, como está a ser usar o algoritmo **round-robin** quem respondeu foi o webserver02

![image](https://user-images.githubusercontent.com/12052283/142946230-5ae43248-35a3-4f74-8a9e-872dbd54d1b1.png)

## Falha com esta experiência

- Nesta experiência é possível identificar 2 *Single Point of Failures*
  - Um no servidor de HAProxy
  - Outro na base de dados
- Ou seja, caso o servidor de HAProxy deixe de operar ou a base de dados, o cliente deixa de ter comunicação com os webservers.
