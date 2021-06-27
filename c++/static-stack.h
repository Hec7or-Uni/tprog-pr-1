# pragma once

const int MAX = 40;

template<typename T>
class static_stack {
	private:
		T datos[MAX];
		int total;

	public:
		static_stack() 
			: total(0)
		{ }

		bool push(const T& e)
		{
			bool sePuede = this->total < MAX;
			if  (sePuede) {
				this->datos[total] = e;
				this->total++;
			}

			return sePuede;
		}

		bool pop() {
			bool sePuede = this->total > 0;
			if (sePuede) this->total--;

			return sePuede;
		}

		friend class const_iterator;

		class const_iterator {
			private:
				const static_stack<T>& stk;
				int i;
			public:
				const_iterator(const static_stack& stk_, int i_) : stk(stk_), i(i_)
				{ }

				const_iterator& operator++() {
					this->i--;
					return (*this);
				}

				const T& operator*() const {
					return this->stk.datos[this->i];
				}

				bool operator!=(const const_iterator& that) const {
					return (this->i != that.i)	? true : false;
				}

		};

		const_iterator begin() const {
			return const_iterator(*this,this->total-1);
		}

		const_iterator end() const {
			return const_iterator(*this,-1);
		}
};
