

class Domain{	
	public:
	template<typename T,typename... Params>
		Reference<T> get(Params... data);
	public:
	template<typename T,typename... Params>
		Reference<T> insert(Params... data);
	public:
	template<typename T,typename... Params>
		Reference<T> remove(Params... data);
};
