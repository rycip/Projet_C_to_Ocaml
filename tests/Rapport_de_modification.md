Correction :
    - Lexer :
        Traitement du '/' pour la division
        Traitement des booleens independamment du reste pour eviter les !true/!false (Nouveau lexeme 'b', peut etre changer)
    - Traducteur :
        - Ponctuation :
            Rajout d'un ; a chaque fin de modification de variable
        - Main :
            Traitement du Nouveau lexeme 'b' (J'ai directement fait dans le main tu peut changer stv)

boucle.c --> mot_cle.c
boucle.h --> mot_cle.h


Ajout :
    - Struct :
        Ajout des variables pour les accolades (j'ai essayé de recopier au max ce que t'avais deja fait pour 
        les parenthese en essayant de comprendre ce que t'avais fait)
    - Lexer : 
        Les variables peuvent désormais contenir des '_'