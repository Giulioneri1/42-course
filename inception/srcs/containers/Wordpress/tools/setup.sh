if  [ ! -f /var/www/wordpress/wp-config.php ]; then

mkdir /var/www
mkdir /var/www/html

chmod 777 /var/www/html
chown -R www-data:www-data *

mv /tmp/wordpress /var/www/html/
mv /tmp/adminer.php /var/www/html/

mv /tmp/docker.png /var/www/html
mv /tmp/index.html /var/www/html
mv /tmp/logo_white_small.png /var/www/html
mv /tmp/style.css /var/www/html

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

sleep 15

wp config create --allow-root --dbname=$WORDPRESS_DB_NAME --dbuser=$WORDPRESS_DB_USER --dbpass=$WORDPRESS_DB_PASSWORD --dbhost=$WORDPRESS_DB_HOST --skip-check --path=/var/www/html/wordpress/
wp core install --allow-root --url=localhost/wordpress --title=$WORDPRESS_DB_NAME --admin_user=$WORDPRESS_DB_USER --admin_password=$WORDPRESS_DB_PASSWORD --admin_email=$WORDPRESS_DB_EMAIL --path=/var/www/html/wordpress/
wp user create --allow-root "${WORDPRESS_USER_LOGIN}" "${WORDPRESS_USER_EMAIL}" --role=subscriber --user_pass="${WORDPRESS_USER_PASSWORD}"  --path=/var/www/html/wordpress

sed -i 's+listen = /run/php/php7.3-fpm.sock+listen = 9000+g' etc/php/7.3/fpm/pool.d/www.conf

fi

service php7.3-fpm start
php -a
php-fpm7.3 --nodaemonize