<h2>Fatec - Faculdade de Tecnologia de Americana</h2>

Sistemas Operacionais II<br>
Professor: Rossano Pablo Pinto<br>
Alunos: 
        <li>Diego Bragante - 0040482011034</li>
        <li>Fellipe Henry Bordon - 0040482011014</li>
        <li>Igor Augusto Compagnol - 0040482011015 </li>
        <li>Vanessa Cristine Hofstatter Held  - 0040482011004</li>
<hr>

Esse projeto foi desenvolvido com o intuito de criar uma ferramenta para autenticação em 2 fatores via módulo PAM.
<br>

<br> ------- Instalação-------<br>

1º deve-se iniciar o terminal e estar logado com o usuário root.<br>
Realizar um git clone do arquivo.<br>
Após download para realizar a instalação usa-se os seguintes comandos:<br>

    $ make
    $ make install

Após os comandos, o modulo é instalado.<br>

Na instalação, cria-se um diretorio chamado pam.usb no caminho /etc/pam.d/. Dentro do pam.usb são criados dois outros arquivos: 
     <li>login: que registra as datas e horas dos logins efetuados.</li>
     <li>usb.serial: onde se encontra o serial de cada dispositivo registrado.</li>
            
Caso queira adicionar um novo dispositivo:

    $ make newdevice

Para desistalar, usa-se o comando:

    $ make uninstall




