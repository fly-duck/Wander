


namespace Wander{

    template<typename T>
    class Status 
    {
        public:

        const T& GetStatus() const;
        
        void SetStatus(T e) ;

        private:

        T energy_;

    

    };


}
