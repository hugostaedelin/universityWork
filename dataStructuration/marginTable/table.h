class Table {
    public :
        Table();
        Table(const Table& t);
        ~Table();
        void ajouter(double v);
        double& operator[](int i);
        double operator[](int i) const;
        int dimension() const;
        void supprimer(int i);
        bool operator==(const Table &t) const;
        Table& operator=(const Table &t);
        void inserer(double v,int i);
    private :
        double* d_table; 	// un tableau dynamique
        int d_n; 		// sa dimension
        int d_capacite; 	// sa capacité
        static const int CI=2; 	// la capacité initiale
        static const int CM=2; 	// un coefficient multiplicateur
};
