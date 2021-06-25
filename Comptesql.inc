<?php

require_once("connexion.inc") ;


// Q 3

  function nouveauCompte($numero,$montant,$cin)
  {
    if(!existeCompte($numero))
    {

    
    global $connect;
    
    $sql = "INSERT INTO compte(numero, montant, cin) VALUES ($numero,$montant,\"$cin\")";      //quand \"$cin\" tu ecrirs $cin sans \"\" n accpete pas les caracteres meme si tu le tape et dan la basedonne tu chosis varchar
    
    $connect->exec($sql);
    
   
    }
    
  }

// Q 2
    
 function  existeCompte($numero)
 {    
       global $connect;
    
    $sql = "SELECT numero FROM compte WHERE numero = $numero ";

    $resultat=$connect->query($sql);
   
    $basedonne = $resultat->fetchAll();// si il exciste il permet de retourner le compte
 
 foreach($basedonne as $ligne) 
 if($ligne["numero"]==$numero) 
 { echo"compte exicte";
   return 1;}
 
 return 0;
        
 }

 

// Q 5

function virement($numero,$valeur)
{
    global $connect;
    
    $sql = "UPDATE compte SET montant=montant+$valeur where numero = $numero";
    
     $connect->exec($sql);
   
  
    

}


// Q 8

function debiteurs()
{

   global $connect;
    
    $sql = "SELECT nom ,prenom FROM client INNER JOIN compte ON client.cin = compte.cin WHERE montant<0";
    
     $resultat=$connect->query($sql);
   
    $basedonne = $resultat->fetchAll();
 
  foreach($basedonne as $ligne)
 
  echo $ligne["nom"]." ".$ligne["prenom"]."<br>"; // ecrire nom et prenom separe par un espace 
    


}


?>