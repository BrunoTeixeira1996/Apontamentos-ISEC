# Aula 14/12/2021

## PPP

- O **PPP** é o protocolo que funciona numa linha qualquer série
- PPP Compress faz com que o quadro fique comprimido, assim os quadros ficam mais pequenos
- **tcp header compression** faz uma compressão só no cabeçalho tcp
  - Ou seja, aqui só vamos comprimir se o pacote for TCP
  - **Isto é bom quando estamos a comunicar sempre para o mesmo pc por exemplo**
  
### Ativar o encapsulamento PPP

```console
conf t
interface serial 0/0
encapsulation ppp
```

### Ping sem compressão

![image](https://user-images.githubusercontent.com/12052283/146679753-88a0a60e-3387-48a0-ad70-d1c0b92ff6f6.png)


### Ping com compressão

![image](https://user-images.githubusercontent.com/12052283/146679766-90546c18-f03e-46d2-97fd-9c161e70c974.png)

## PPPP Multilink

- A partir de determinado nível de ocupação de uma ligação a carga pode passar a ser distríbuida por novas ligações estabelecidas entre os extremos se tal for possível
- Os quadros passam a ser fragmentados

![image](https://user-images.githubusercontent.com/12052283/146679822-c1960f13-031a-4034-b70e-948704a6060b.png)

### Configuração do Multilink

![image](https://user-images.githubusercontent.com/12052283/146679856-c7fdf132-c3e9-44f8-936f-5dd99e5dc885.png)


## PAP (Password Authentication Protocol)

- **Aqui as credênciais não ficam encriptadas**
- **A password pode ser diferente em cada lado**

![image](https://user-images.githubusercontent.com/12052283/146679898-e2042dcf-3c77-4cc5-a5b3-36e0842ac4a6.png)


## CHAP (Challenge Handshake Authentication Protocol)

- **Aqui as credênciais ficam encriptadas**

![image](https://user-images.githubusercontent.com/12052283/146679942-a1d9a656-88ab-49c3-b775-2b3a83a627b5.png)

## PPPoFR (PPP over Frame Relay)

![image](https://user-images.githubusercontent.com/12052283/146680004-d2a23fef-6ce7-49d8-87de-c021b2b8fab5.png)

## Multilink PPPoFR (Multilink PPP over Frame Relay)

![image](https://user-images.githubusercontent.com/12052283/146680073-f6cbb600-462f-426f-a61e-820347bca1cd.png)


## QinQ

- É conhecida por VLAN dot1q tunnel
- É basicamente termos uma vlan em cima de outra, por exemplo para ligar vlans entre empresas diferentes
- tirar print à pagina 2 do QinQ(a azul colocamos a vlan do isp e a amarelo a vlan do cliente)
- tirar print à pagina 3,4 do QinQ
