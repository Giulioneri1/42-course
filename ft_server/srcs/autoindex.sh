if (cat /etc/nginx/sites-available/default | grep "autoindex on")
then
    cp /tmp/default_autoindex_off /etc/nginx/sites-available/default ;
    #else cp /tmp/default_autoindex_off /etc/nginx/sites-available/default ; fi
else
    cp /tmp/default_autoindex_on /etc/nginx/sites-available/default ;
    #else cp /tmp/default_autoindex_off /etc/nginx/sites-available/default ; fi
fi
service nginx restart