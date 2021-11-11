/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:48:11 by gneri             #+#    #+#             */
/*   Updated: 2021/11/09 12:48:11 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class contact
{
    private: //ATTRIBUTI SPECIFICI DI OGNI FUTURO OGGETTO CREATO
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phonenumber;
        std::string darkest_secret;
        bool        fill;
    public: //METODI/AZIONI ESEGUITI DALL'OGGETTO --> FUNZIONI
        contact(); //COTRUTTORE DI OGGETTI 
        void			set_first_name(std::string s);
		void			set_last_name(std::string s);
		void			set_nickname(std::string s);
		void			set_phonenumber(std::string s);
		void			set_darkest_secret(std::string s);
        void            set_fill();

        std::string		get_first_name();
        std::string		get_last_name();
        std::string		get_nickname();
        std::string		get_phonenumber();
        std::string		get_darkest_secret();
        bool            get_fill();
};

#endif 