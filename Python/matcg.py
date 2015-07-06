from mpl_toolkits.mplot3d import Axes3D
from pylab import *

class Painter(object):
    def __init__(self, fig):
        self.axes = Axes3D(fig)
        pass

    def drawXYZ(self):
    	self.axes.plot([-2, 2], [0, 0], [0, 0], color="red")
    	self.axes.plot([1.99, 2], [0, 0], [0, 0], "<", color="red")
    	self.axes.text(2, 0, 0, "X", color="red")
    	self.axes.plot([0, 0], [-2, 2], [0, 0], color="green")
    	self.axes.plot([0, 0], [1.99, 2], [0, 0], "<", color="green")
    	self.axes.text(0, 2, 0, "Y", color="green")
    	self.axes.plot([0, 0], [0, 0], [0, 2], color="orange")
    	self.axes.plot([0, 0], [0, 0], [1.99, 2], "<", color="orange")
    	self.axes.text(0, 0, 2, "Z", color="orange")

    def drawFrame(self, ix, iy, iz, icolor="grey"):
        self.axes.plot_wireframe(ix, iy, iz, color=icolor)
        pass

    def drawLine2D(self, begin, end, istyle="", icolor="blue"):
        self.axes.plot([begin[0], end[0]], [begin[1], end[1]],
            istyle, color=icolor)
        pass

    def drawLine3D(self, begin, end, istyle="", icolor="blue"):
        self.axes.plot([begin[0], end[0]],
            [begin[1], end[1]], [begin[2], end[2]],
            istyle, color=icolor)
        pass

    def drawVecLine(self, begin, end, icolor="blue"):
        self.axes.plot([begin[0], end[0]],
            [begin[1], end[1]], [begin[2], end[2]],
            color=icolor)
        self.axes.plot([end[0] - 0.001 * (end[0] - begin[0]), end[0]],
            [end[1] - 0.001 * (end[1] - begin[1]), end[1]], 
            [end[2] - 0.001 * (end[2] - begin[2]), end[2]],
            "<", color=icolor)
        pass

    def drawPoint(self, point, icolor="blue"):
        self.axes.text(point[0], point[1], point[2],
        	"P(%.2f, %.2f, %.2f)" % (point[0], point[1], point[2]), 
        	color=icolor)
        pass

    def drawText(self, point, text, icolor="blue"):
        self.axes.text(point[0], point[1], point[2],
        	text, color=icolor)
        pass

    def show(self):
        show()
        pass
    pass

if __name__ == '__main__':
    pi_div4 = pi / 4
    fig = figure()
    #axes = Axes3D(fig)
    painter = Painter(fig)

    #plane
    X = arange(0, 2, 0.1)
    Y = arange(-1, 1, 0.1)
    x, y = meshgrid(X, Y)
    z = abs(x) / 2

    #spherical
    #A = arange(0, 2 * pi + 1, 0.05 * pi)
    #Z = arange(0, 2, 0.5)
    #a, z = meshgrid(A, Z)
    #x = 2 * cos(a)
    #y = 2 * sin(a)

    #Cylindrical
    #u = arange(0, 2 * pi + 1, 0.05 * pi)
    #v = arange(0, pi / 2 + 0.05 * pi, 0.05 * pi)
    #x = 2 * outer(cos(u), sin(v)) 
    #y = 2 * outer(sin(u), sin(v)) 
    #z = 2 * outer(ones(size(u)), cos(v))

    painter.drawXYZ()
    painter.drawFrame(x, y, z)
    """x0 = 2 * cos(pi_div4) * sin(pi_div4)
    y0 = -2 * sin(pi_div4) * cos(pi_div4)
    z0 = 2 * cos(pi_div4)
    painter.drawVecLine([0, 0, 0], [x0, y0, z0])
    painter.drawLine2D([0, 0], [x0, y0], "--")
    painter.drawLine2D([0, 0], [x0, 0], "--")
    painter.drawLine2D([0, 0], [0, y0], "--")
    painter.drawLine2D([0, y0], [x0, y0], "--")
    painter.drawLine2D([x0, 0], [x0, y0], "--")
    painter.drawLine3D([x0, y0, 0], [x0, y0, z0], "--")
    painter.drawPoint([x0, y0, 0])
    painter.drawPoint([x0, y0, z0])"""

    painter.show()
    #show()
    pass
