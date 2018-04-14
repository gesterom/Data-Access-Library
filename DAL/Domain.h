

class Domain{	
	public:
	template<typename T,typename... Params>
		Res<T> get(Params... data);
	public:
	template<typename T,typename... Params>
		Res<T> insert(Params... data);
	public:
	template<typename T,typename... Params>
		Res<T> remove(Params... data);
};
