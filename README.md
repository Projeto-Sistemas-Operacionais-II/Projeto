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

Na instalação foram criado uma pasta e dois arquivos:
    <br><li> /etc/pam.d/pam.usb</li> 
    <br>login: localiza-se o arquivo login que registar as datas e horas dos logins efetuados.<br>
    <br>usb serial: localiza-se os arquivos com o os seriais dos pendrives, juntamento com a data e hora dos .
        

Para desistalar, usa-se o comando:

    $ make uninstall

Para adicionar um novo pendrive:

    $ make addpendrive


