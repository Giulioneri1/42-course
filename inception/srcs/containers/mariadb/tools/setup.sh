if [ ! -d "/var/lib/mysql/wordpress" ]; then

apt install -y mariadb-server

mv /tmp/50-server.cnf /etc/mysql/mariadb.conf.d

mysql_install_db --user=mysql --datadir='/mariadb'
cat << EOF > /tmp/init.sql
CREATE DATABASE $WORDPRESS_DB_NAME;
CREATE USER '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PASSWORD';
GRANT ALL ON *.* TO '$WORDPRESS_DB_USER'@'%' IDENTIFIED BY '$WORDPRESS_DB_PASSWORD' WITH GRANT OPTION;
ALTER USER 'root'@'localhost' IDENTIFIED BY '$ROOT_PASSWORD';
FLUSH PRIVILEGES;
EOF
cd '/usr' ; /usr/bin/mysqld_safe --datadir='/mariadb' --init-file=/tmp/init.sql

else
cd '/usr' ; /usr/bin/mysqld_safe --datadir='/mariadb'

fi
