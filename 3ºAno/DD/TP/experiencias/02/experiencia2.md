# Experiência 02

## Resultado

- Fez-se uma captura no HAProxy01(MASTER) e no HAProxy02(BACKUP)
- Conseguimos ver na captura que o HAProxy01(192.168.1.183) de 1 em 1 segundo faz um Advertisement dizendo a sua prioridade(101) (no VRRP apenas o MASTER emite mensagens, os outros BACKUPs estão à escuta)
- Enquanto que na captura do HAProxy02 vemos então as mensagens enviadas pelo HAProxy01

IMAGEM WIRESHARK
IMAGEM TERMINAL

- Ao desligarmos o serviço HAProxy do 192.168.1.183, o mesmo fica com uma prioridade de 91 passando assim para o estado de BACKUP ao mesmo tempo que o HAProxy02 passa para o estado de MASTER uma vez que a sua prioridade é superior (100)

IMAGEM WIRESHARK
IMAGEM TERMINAL

- Depois de voltar ativar o serviço haproxy no HAProxy01(192.168.1.183) o mesmo torna-se novamente MASTER pois a preempção está ativa por omissão fazendo com que a sua prioridade volte a ser 101 como estava definida inicialmente.

IMAGEM WIRESHARK
IMAGEM TERMINAL

## Falha com esta experiência
