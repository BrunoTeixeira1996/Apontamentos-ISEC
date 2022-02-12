# Aula 11/01/2022

## Configurações no AP - Rede 1

- Abrir um novo SSID
- Configurar interface dhcp com ip
- Vamos ao radio a 2.4Ghz
- Vamos ao radio 5.0Ghz

```console
conf t
dot11 ssdi TL
authentication open
authentication key-management wpa version 2
guest-mode
wpa-psk ascii 1234567890
exit

int bvi 1
ip add dhcp

int dot11Radio 0
encryption mode ciphers aes
ssdi TL
power local 5
no shut


int dot11Radio 1
encryption mode ciphers aes
ssdi TL
channel 36
no shut
```

## Notas

- A password nos APs da cisco é sempre `Cisco`
- Se baixarmos o `power local` a nossa frequencia baixa
- `sudo iwlist <interface> scan | grep "Frequency"` faz com que se veja a frequência dos canais em linux
