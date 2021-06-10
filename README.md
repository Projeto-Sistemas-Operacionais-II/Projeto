<h2>Fatec - Faculdade de Tecnologia de Americana</h2>

Sistemas Operacionais II<br>
Professor: Rossano Pablo Pinto<br>
Alunos: 
        <li>Diego Bragante - 0040482011034</li>
        <li>Fellipe Henry Bordon - 0040482011014</li>
        <li>Igor Augusto Compagnol - 0040482011015 </li>
        <li>Vanessa Cristine Hofstatter Held  - 0040482011004</li>
<hr>

Esse projeto foi desenvolvido com o intuito de criar uma ferramenta para autenticação em 2 fatores via módulo PAM_USB.
<br>

<br> ------- Instalação-------<br>

1º deve-se iniciar o terminal e estar logado com o usuário root.<br>
Realizar um git clone do arquivo.<br>
Após download para realizar a instalação usa-se os seguintes comandos:<br>

    $ make
    $ make install

Após os comandos o modulo foi instalado.<br>

Na instalação foram criados duas pastas e dois arquivos:
    <br><li> /etc/pam.d/pam.pdrive</li>
    <b>login</b>: localiza-se os arquivos com o os seriais dos pendrives.
    <br><li>/etc/pam.d/pam.pdrive/log</li>
    <b>log</b>: aqui se encontra os arquivo de log, regisstrando data e hora juntamente com os login efetuados.<br>

Para desistalar, usa-se o comando:

    $ make uninstall

Para adicionar um novo pendrive:

    $ make addpendrive


