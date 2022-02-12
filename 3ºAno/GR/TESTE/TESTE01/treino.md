# Enunciado

- Os PCs tem sempre os primeiros IPs da subrede a que pertencem e de acordo com o seu número
- Os Routers tem o ultimo IP da subrede a que pertencem
- Na interligação série, o router Coimbra1 tem os primeiros IPs de cada subrede

## IPs

- Coimbra1 - até 60 máquinas
  2^6 = 64 -> 62 hosts disponíveis
  32-6 = `/26 (255.255.255.192)`
  (Rede + Hosts) - 1
  **Resultado** = `192.168.0.0(Rede)-192.168.0.63(Broadcast)`

- Coimbra2 - até 60 máquinas
  2^6 = 64 -> 62 hosts disponíveis
  32-6 = `/26 (255.255.255.192)`
  (Rede + Hosts) - 1
  **Resultado** = `192.168.0.64(Rede)-192.168.0.127(Broadcast)`

- Combra1-Coimbra2 - até 2 máquinas
  2^2 = 4 -> 2 hots disponíveis
  32-2 = `/30 (255.255.255.252)`
  (Rede + Hosts) - 1
  **Resultado** = `192.168.0.128(Rede)-192.168.0.131(Broadcast)`

- CoimbraLisboa   CoimbraPorto
  - `10.0.0.0/29 (255.255.255.248)`

- Lisboa
	- `192.168.1.0/24(255.255.255.0) `
  
- Porto
  - `192.168.2.128/25(255.255.255.128)`

## Resolução

- IP mal na fa0/0 no router Coimbra2
  - Trocar por `ip add 192.168.0.126 255.255.255.128`

- Version RIP v1 no Coimbra2
  - Trocar por `version 2`

- IP e máscara mal na se0/0 no router Porto
  - Trocar por `ip add 10.0.0.6 255.255.255.252`

- IP e máscara mal no PC7 do Porto
  - Trocar por `192.168.2.130` com a máscara `255.255.255.128`

- IP mal na f0/0 do router Lisboa
  - Trocar por `ip add 192.168.1.254 255.255.255.0`
  
