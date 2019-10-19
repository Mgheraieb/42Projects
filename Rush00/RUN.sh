#!/bin/bash
echo "[ \033[32mOK\033[0m ]\tLancement de RUN.sh."
sleep 2

read -p "Nom du serveur: " servername
sleep 2

echo "[ \033[32mOK\033[0m ]\tCreation de la VM."
sleep 2
docker-machine create $servername

echo "[ \033[32mOK\033[0m ]\tDemarrage de la VM."
sleep 2
docker-machine start $servername

echo "[ \033[32mOK\033[0m ]\tAjout des variables d'environnement."
sleep 2
docker-machine env $servername
eval "$(docker-machine env $servername)"

echo "[ \033[32mOK\033[0m ]\tLancement de container."
sleep 2
docker-compose up -d

echo "[ \033[32mOK\033[0m ]\tAdresse de la VM:"
sleep 2
docker-machine ip $servername

echo "[ \033[32mOK\033[0m ]\tConnexion a la VM."
sleep 2
docker exec -it rush00_www_1 /bin/bash
