# VM Instruction Set

| Opcode | Mnemonic     | Description                                                                              | Arguments | Pops | Pushes |
|--------|--------------|------------------------------------------------------------------------------------------|-----------|------|--------|
| 0x01   | LOAD_VAL     | Empile une valeur numérique (int32) sur la pile.                                         | 1         | 0    | 1      |
| 0x02   | READ_VAR     | Empile la valeur de la variable spécifiée (uint8 pour l'ID de la variable).              | 1         | 0    | 1      |
| 0x03   | STORE_VAR    | Stocke la valeur au sommet de la pile dans une variable.                                  | 1         | 1    | 0      |
| 0x04   | ADD          | Additionne les deux valeurs au sommet de la pile.                                         | 0         | 2    | 1      |
| 0x05   | SUB          | Soustrait la valeur au sommet de la pile par celle juste en dessous.                      | 0         | 2    | 1      |
| 0x06   | MUL          | Multiplie les deux valeurs au sommet de la pile.                                          | 0         | 2    | 1      |
| 0x07   | DIV          | Divise la valeur juste en dessous par celle au sommet de la pile.                         | 0         | 2    | 1      |
| 0x08   | MOD          | Prend le modulo de la valeur juste en dessous par celle au sommet de la pile.             | 0         | 2    | 1      |
| 0x09   | JMP          | Saute à l'instruction en se décalant de la valeur de l'offset (int32).                    | 1         | 0    | 0      |
| 0x0A   | JMP_IF_ZERO  | Saute à l'instruction en se décalant de la valeur de l'offset (int32) si la valeur au sommet de la pile est 0. | 1         | 1    | 0      |
| 0x0B   | JMP_IF_TRUE  | Saute à l'instruction en se décalant de la valeur de l'offset (int32) si la valeur au sommet de la pile est vraie. | 1         | 1    | 0      |
| 0x0C   | EQ           | Empile 1 si les deux valeurs au sommet de la pile sont égales, 0 sinon.                   | 0         | 2    | 1      |
| 0x0D   | NEQ          | Empile 1 si les deux valeurs au sommet de la pile sont différentes, 0 sinon.              | 0         | 2    | 1      |
| 0x0E   | GT           | Empile 1 si la valeur juste en dessous est plus grande que celle au sommet de la pile, 0 sinon. | 0         | 2    | 1      |
| 0x0F   | LT           | Empile 1 si la valeur juste en dessous est plus petite que celle au sommet de la pile, 0 sinon. | 0         | 2    | 1      |
| 0x10   | GTE          | Empile 1 si la valeur juste en dessous est plus grande ou égale à celle au sommet de la pile, 0 sinon. | 0         | 2    | 1      |
| 0x11   | LTE          | Empile 1 si la valeur juste en dessous est plus petite ou égale à celle au sommet de la pile, 0 sinon. | 0         | 2    | 1      |
| 0x12   | PRINT_VAL    | Affiche la valeur au sommet de la pile.                                                   | 0         | 1    | 0      |
| 0x13   | INPUT_VAL    | Demande à l'utilisateur de rentrer une valeur et l'empile sur la pile.                    | 0         | 0    | 1      |
| 0x14   | HALT         | Arrête l'exécution du programme.                                                          | 0         | 0    | 0      |
| 0x15   | LOAD_STR     | Empile une chaîne de caractères sur la pile.                                              | 1         | 0    | 1      |
| 0x16   | PRINT_STR    | Affiche la chaîne de caractères au sommet de la pile.                                      | 0         | 1    | 0      |
| 0x17   | INPUT_STR    | Demande à l'utilisateur de rentrer une chaîne de caractères et l'empile sur la pile.      | 0         | 0    | 1      |
| 0x18   | STR_LEN      | Empile la longueur de la chaîne de caractères au sommet de la pile.                        | 0         | 1    | 1      |
| 0x19   | CONCAT       | Concatène les deux chaînes de caractères au sommet de la pile.                             | 0         | 2    | 1      |
| 0x1A   | GET_CHAR     | Empile le caractère à l'index donné de la chaîne de caractères au sommet de la pile.      | 0         | 1    | 1      |
| 0x1B   | SET_CHAR     | Modifie le caractère à l'index donné de la chaîne de caractères au sommet de la pile.    | 3         | 0    | 0      |
| 0x1C   | STR_CMP      | Empile 1 si les deux chaînes de caractères au sommet de la pile sont égales, 0 sinon.     | 0         | 2    | 1      |
