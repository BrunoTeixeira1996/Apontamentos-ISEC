# Aula 14/01/2022

## Esquema

![image](https://user-images.githubusercontent.com/12052283/149539155-85bc8fe1-721e-4479-8221-cfdaef228fc6.png)

- Rede A (`192.168.6.0/24`)
  - PC -> 192.168.6.1
  - RA -> 192.168.6.55

- Rede RA-RC (`10.0.0.0/30`)
  - RA -> 10.0.0.1/30
  - RC -> 10.0.0.2/30

### Perguntas

- **Nome do router onde estamos**

```console
snmpget -v 1 -c public -d <ip do Router> sysName.0
```

- **Localização do router**

```console
snmpget -v 1 -c public -d <ip do Router> sysLocation.0
```

- **Ip do router onde estamos**

```console
fazemos ipconfig
```

- **Descobrir a tabela de encaminhamento**

1º alternativa

```console
snmpwalk -v 2c -c public <ip do router> ip | more
```

2º alternativa

```console
snmpwalk -v 2c -c public <ip do router> ipRouteTable
```

- Se usarmos o next-hop é aqui que descobrimos tudo, conseguimos saltar para os outros routers

```console
snmpwalk -v 2c -c public <ip do router> ipRouteNextHop
```

- **Descobrir as interfaces que existem num router**

```console
snmpwalk -v 2c -c public <ip do router> IfDescr
```

- **Descobrir o ip das interfaces da melhor maneira**

```console
snmpwalk -v 2c -c public <ip do router> ipAddrTable && snmpwalk -v 2c -c public <ip do router> ifDescr
```

- **Descobrir os Ips das interfaces dos routers**

```console
snmpwalk -v 2c -c public <ip do router> ipAddrTable
```

![image](https://user-images.githubusercontent.com/12052283/149559230-2690ac95-c0a0-496c-975d-5924054c8556.png)
