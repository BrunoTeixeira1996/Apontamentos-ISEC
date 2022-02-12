# Aula T 03/11/2021

- Uma solução para lidar com as atualizações conflituantes é ter um algoritmo de resolução de conflitos para resolver a discrepância nos valores.

- **Uma das hipóteses é definir que o DC no qual as alterações foram gravadas por último seja o vencedor e as alterações em todos os outros DCs são descartadas**

## Flexible Single Master Operation

- Basicamente é definir quem é que faz o que

- Por omissão o primeiro servidor na rede vai ter os cinco FSMO

### Schema Master

- *The Schema Master role manages the read-write copy of your Active Directory schema. The AD Schema defines all the attributes – things like employee ID, phone number, email address, and login name – that you can apply to an object in your AD database.*

### Domain Namin Master

- *The Domain Naming Master makes sure that you don’t create a second domain in the same forest with the same name as another. It is the master of your domain names. Creating new domains isn’t something that happens often, so of all the roles, this one is most likely to live on the same DC with another role.*

### RID Master

- *The Relative ID Master assigns blocks of Security Identifiers (SID) to different DCs they can use for newly created objects. Each object in AD has an SID, and the last few digits of the SID are the Relative portion. In order to keep multiple objects from having the same SID, the RID Master grants each DC the privilege of assigning certain SIDs.*

### PDC Emulator

- *The DC with the Primary Domain Controller Emulator role is the authoritative DC in the domain. The PDC Emulator responds to authentication requests, changes passwords, and manages Group Policy Objects. And the PDC Emulator tells everyone else what time it is! It’s good to be the PDC.*

### Infrastructure Master

- *The Infrastructure Master role translates Globally Unique Identifiers (GUID), SIDs, and Distinguished Names (DN) between domains. If you have multiple domains in your forest, the Infrastructure Master is the Babelfish that lives between them. If the Infrastructure Master doesn’t do its job correctly you will see SIDs in place of resolved names in your Access Control Lists (ACL).*

### Conclusão

- Se a máquina que manda no *Domain Naming Master* for à vida não é grave porque não estamos constantemente a criar dominios, no entanto se a máquina mandar no *Schema Master* for à vida é grave porque é aqui que está a base de dados que suporta o conjunto de objetos da AD usado na floresta

- Não ha problema em termos dois serviços numa só máquina, dependendo claro dos serviços usados

## Relação de confiança

- Método de criação
  - Se é normal ou explicito
  - Se é automático ou implicito
  

- Tipo
  - Externa
  - Realm
  - Floresta
  - Atalho
  
### Transitividade

- Se A confia em B e B confia em C, então A confia em C
- No entanto isto pode ser retirado

### Direção

- Num sentido
  - D1 confia em D2 apenas
  
- Em ambos os sentidos
  - D1 confia em D2 e D2 confia em D1


