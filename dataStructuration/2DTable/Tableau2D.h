class Tableau2D {
    public :
        Tableau2D();
        Tableau2D(int nl, int nc);
        Tableau2D(const Tableau2D& t);
        ~Tableau2D();
        double& operator()(int l, int c);
        double operator()(int l, int c) const; 
        int get_nl() const;
        int get_nc() const;
        bool operator==(const Tableau2D &t) const;
        Tableau2D& operator=(const Tableau2D &t);
    private :
        // Il faut connaître le nombre de lignes
        // et le nombre de colonnes
        int d_nl, d_nc;
        // Le tableau contigu
        double *d_v;
        // Le tableau de pointeurs sur les « lignes »
        double **d_tab;
};