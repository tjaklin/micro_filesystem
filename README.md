# README

x Dost ruzno je organizirano. Sve klase na A implementiraju sucelje Action iz Action.hpp.
x Node, File i Directory se ticu filesystem-a.
x Action i klase koje implementiraju sucelje sluze za jednostavno definiranje novih komandi - npr. Print za ls komandu, Delete za rm komandu, ...
x Command, CommandFactory se ticu citanja i parsiranja korisnikovih naredbi, a nakon toga i pozivanja odgovarajucih Action* objekata za 
  izvrsavanje zeljenih naredbi.
  
x c++11.
