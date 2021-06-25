 <?php

// préparation des informations nécessaires 

define("DSN","mysql:host=localhost;dbname=bmce banque"); 
define("USER","root");
define("MDP","");

// create objet PDO and connect to the server WAMP

$connect=new PDO(DSN,USER,MDP); //on utiliser pdo car avoir la cpnnection avec sql en meme temps pour utiliser une fct fetchall

 
?> 
