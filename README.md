
# Implementação do Algoritmo de Análise do Valor Médio

Implementamos de forma simplificada o Algoritmo de Análise do Valor Médio (MVA). Uma técnica importante na análise da teoria das filas.


## Compilando e executando:

**Necessário possuir compilador de C++**

Clone primeiramente o repositório. Utilize a branch *main* (default).

Execute os comandos abaixo na pasta raiz.

```bash
  g++ main.cpp mva.cpp -o simulador
```

Com o executável compilado, já é possível utilizá-lo de forma livre.

Para rodar os casos de teste preparados, rode o comando:
    
```bash
  Get-Content .\caso_de_teste_X.txt | .\simulador.exe
```
*Troque o X pelo número do caso de texte (1 a 3). Esse comando funciona no PowerShell.*
## Utilizando

**É necessário colocar todos os tempos de entrada para segundos.**

### Dados de entrada:

| Entrada   | Tipo       | Descrição                           |
| :---------- | :--------- | :---------------------------------- |
| `N` | `int` | Número de clientes |
| `λ` | `double` | Taxa de chegada global |
| `Recursos` | `int` | Número de filas do sistema |

- Para cada Recurso, é solicitado:

    | Entrada   | Tipo       | Descrição                           |
    | :---------- | :--------- | :---------------------------------- |
    | `Nome` | `string` | Nome do recurso |
    | `µ` | `double` | Taxa de serviço do recurso |
    | `λk` | `double` | Taxa de chegada local (para calcular visitas) |

### Saída do programa:

Resultados globais do sistema:

| Varíavel   | Descrição       | Valor                           |
| :---------- | :--------- | :---------------------------------- |
| `R` | `Tempo Médio de Resposta` | `em segundos` |
| `W` | `Tempo Médio de Espera` | `em segundos` |
| `U` | `Utilização do Sistema` | `em porcentagem` |
| `L` | `Clientes no Sistema` | `em quantidade` |
| `X` | `Throughput do Sistema` | `em clientes/unidade de tempo` |

- Para cada Recurso, é retornado:

    | Recurso   | R | W | U | L |
    | :---------- | :--------- | :--------- | :--------- | :--------- |
    | `Nome do recurso` | `Tempo de resposta do recurso` | `Tempo de espera do recurso` | `Porcentagem de utilização do recurso` | `Número de clientes no recurso`



