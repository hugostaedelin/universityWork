#ifndef INTERVALLE_H
#define INTERVALLE_H


class intervalle{
public:
    intervalle();
    intervalle(double min,double max);
    double min() const;
    double max() const;
    void changeMin(double min);
private:
    double d_max,d_min;
};


#endif // INTERVALLE_H
