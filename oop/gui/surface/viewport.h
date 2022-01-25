#ifndef VIEWPORT_H
#define VIEWPORT_H

class viewport
{
public:
    viewport();
    viewport(int xleft, int ybottom, int xright, int ytop);
    int xLeft() const;
    int xRight() const;
    int yBottom() const;
    int yTop() const;
    double xMin() const;
    double xMax() const;
    double yMin() const;
    double yMax() const;
    double dx() const;
    double dy() const;
    int width() const;
    int height() const;
    double xRange() const;
    double yRange() const;
    int xVersPixel(double x) const;
    int yVersPixel(double y) const;
    double pixelVersX(int x) const;
    double pixelVersY(int y) const;
    void changeWindow(int xleft, int ybottom, int xright, int ytop);
    void changeWindowX(int xleft, int xright);
    void changeWindowY(int ybottom, int ytop);
    void changeFrame(double xmin, double xmax, double ymin, double ymax);
    void changeFrameX(double xmin, double xmax);
    void changeFrameY(double ymin, double ymax);
private:
    int d_xleft, d_ybottom, d_xright, d_ytop;
    double d_xmin, d_xmax, d_ymin, d_ymax;
    double d_dx,d_dy;
    void updateDX();
    void updateDY();
};

#endif // VIEWPORT_H
