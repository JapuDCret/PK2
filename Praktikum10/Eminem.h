#ifndef EMINEM_H_
#define EMINEM_H_

namespace pk2 {
	template<class T>
	class Eminem
	{
	private:
		T* content;
		Eminem* next;
	public:
		Eminem(T* o, Eminem* e = nullptr) : content{ o }, next{ e } {};
		T* get_content() const { return content;	}
		Eminem* get_next() const { return next; }
		void set_next(Eminem* n) { next=n; }	};
}

#endif