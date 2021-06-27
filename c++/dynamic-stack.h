# pragma once

template<typename T>
class dynamic_stack {
    private:
        class Nodo {
            public:
                T dato;
                Nodo* sig;
        };

        Nodo* cima;

    public:
        dynamic_stack() 
            : cima(nullptr) 
        { }

        bool push(const T& e) {
            Nodo* nuevo = new Nodo;
            nuevo->dato = e;
            nuevo->sig = this->cima;
            this->cima = nuevo;
            return true;
        }

        bool pop() {
            bool sePuede = this->cima != nullptr;
            Nodo* aux;

            if (sePuede) {
                aux = this->cima;
                this->cima = this->cima->sig;
                delete aux;
            }

            return sePuede;
        }

        friend class const_iterator;

        class const_iterator {
            private:
                Nodo* iter;
            public:
                const_iterator(Nodo* iter_) 
                    : iter(iter_)
                { }

                const_iterator& operator++() {
                    iter =  iter->sig;
                    return (*this);
                }

                const T& operator*() const {
                    return this->iter->dato;
                }

                bool operator!=(const const_iterator& that) const {
                    return this->iter != that.iter;
                }
        };

        const_iterator begin() const {
            return const_iterator(this->cima);
        }
        
        const_iterator end() const {
            return const_iterator(nullptr);
        }
};
