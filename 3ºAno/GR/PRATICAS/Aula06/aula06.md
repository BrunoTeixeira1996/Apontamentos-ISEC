# Aula 03/12/2021

## Instalar NET-SNMP no Linux

- https://support.auvik.com/hc/en-us/articles/204221884-How-to-enable-SNMP-on-Linux-based-servers-workstations

- Executando `snmpget -v 1 -c public 127.0.0.1 sysName.0` deve retornar o nome da máquina

- Com o snmpwalk conseguimos ver as coisas d emaneira mais fácil
- Por exemplo vermos as descrição das interfaces
  - `snmpwalk -v 1 -c public 127.0.0.1 ifDescr`

- Para vermos o UpTime do sistema
  - `snmpwalk -v 1 -c public 127.0.0.1 system.sysUpTime`
