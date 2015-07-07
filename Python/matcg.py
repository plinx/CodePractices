from mpl_toolkits.mplot3d import Axes3D
from pylab import *

class Painter(object):
    def __init__(self, fig):
        self.axes = Axes3D(fig)
        pass

    def drawXYZ(self, length=2):
        self.axes.plot([-length, length], [0, 0], [0, 0], color="red")
        self.axes.plot([length - 0.01, length], [0, 0], [0, 0], "<", color="red")
        self.axes.text(length, 0, 0, "X", color="red")
        self.axes.plot([0, 0], [-length, length], [0, 0], color="green")
        self.axes.plot([0, 0], [length - 0.01, length], [0, 0], "<", color="green")
        self.axes.text(0, length, 0, "Y", color="green")
        self.axes.plot([0, 0], [0, 0], [0, length], color="orange")
        self.axes.plot([0, 0], [0, 0], [length - 0.01, length], "<", color="orange")
        self.axes.text(0, 0, length, "Z", color="orange")

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

    def drawPointLabel(self, x, y, z):
        self.drawVecLine([0, 0, 0], [x, y, z])
        self.drawLine2D([0, 0], [x, y], "--")
        self.drawLine2D([0, 0], [x, 0], "--")
        self.drawLine2D([0, 0], [0, y], "--")
        self.drawLine2D([0, y], [x, y], "--")
        self.drawLine2D([x, 0], [x, y], "--")
        self.drawLine3D([x, y, 0], [x, y, z], "--")
        self.drawPoint([x, y, 0])
        self.drawPoint([x, y, z])
        pass

    def show(self):
        show()
        pass

    def planeDemo(self):
        #plane
        X = arange(0, 2, 0.1)
        Y = arange(-1, 1, 0.1)
        x, y = meshgrid(X, Y)
        z = abs(x) / 2
        self.drawXYZ()
        self.drawFrame(x, y, z)
        pass

    def sphericalDemo(self):
        #spherical
        A = arange(0, 2 * pi + 1, 0.05 * pi)
        Z = arange(0, 2, 0.5)
        a, z = meshgrid(A, Z)
        x = 2 * cos(a)
        y = 2 * sin(a)
        self.drawXYZ()
        self.drawFrame(x, y, z)

        x0 = 2 * cos(pi_div4)
        y0 = -2 * sin(pi_div4)
        z0 = 1
        return x0, y0, z0
        pass

    def cylindricalDemo(self):
        #cylindrical
        u = arange(0, 2 * pi + 1, 0.05 * pi)
        v = arange(0, pi / 2 + 0.05 * pi, 0.05 * pi)
        x = 2 * outer(cos(u), sin(v)) 
        y = 2 * outer(sin(u), sin(v)) 
        z = 2 * outer(ones(size(u)), cos(v))
        self.drawXYZ()
        self.drawFrame(x, y, z)

        x0 = 2 * cos(pi_div4) * sin(pi_div4)
        y0 = -2 * sin(pi_div4) * cos(pi_div4)
        z0 = 2 * cos(pi_div4)
        return x0, y0, z0
        pass

    def triangleDemo(self):
        #triangle
        self.drawXYZ()
        s = arange(0, 1.05, 0.05)
        z = outer(abs(s), s)
        x = outer(2 - abs(s), s) - 2
        y = outer(0, s)
        self.drawFrame(x, y, z, "blue")
        z = outer(abs(s), s) + 0.5
        x = outer(2 - abs(s), s)
        self.drawFrame(x, y, z, "orange")

    def cicleDemo(self):
        #cicle
        self.drawXYZ()
        s = arange(0, 2.05 * pi, 0.05 * pi)
        z = outer(0.05 * sin(s), s) + 0.3
        x = outer(0.05 * cos(s), s) - 0.3
        y = outer(0, s)
        self.drawFrame(x, y, z, "orange")

        z = outer(0.02 * sin(s), s) + 0.2
        x = outer(0.02 * cos(s), s) + 0.2
        y = outer(0, s)
        self.drawFrame(x, y, z, "orange")

        z = outer(0.02 * sin(s), s) + 0.7
        x = outer(0.02 * cos(s), s) + 1.2
        y = outer(0, s) + 0.2
        self.drawFrame(x, y, z)

        z = outer(0.03 * sin(s), s) + 0.5
        x = outer(0.03 * cos(s), s) - 0.5
        y = outer(0, s) + 0.5
        self.drawFrame(x, y, z)

        self.drawLine3D([0, -1, 0], [1, 1, 0], "--")
        self.drawLine3D([0, -1, 0], [-1, 1, 0], "--")
        self.drawLine3D([0, -1, 0], [1, 1, 1], "--")
        self.drawLine3D([0, -1, 0], [-1, 1, 1], "--")

        self.drawLine3D([0.25, -0.5, 0], [0.25, -0.5, 0.25], "-", "green")
        self.drawLine3D([-0.25, -0.5, 0], [-0.25, -0.5, 0.25], "-", "green")
        self.drawLine3D([-0.25, -0.5, 0], [0.25, -0.5, 0], "-", "green")
        self.drawLine3D([-0.25, -0.5, 0.25], [0.25, -0.5, 0.25], "-", "green")

        self.drawLine3D([0.5, 0, 0], [0.5, 0, 0.5], "-", "green")
        self.drawLine3D([-0.5, 0, 0], [-0.5, 0, 0.5], "-", "green")
        self.drawLine3D([-0.5, 0, 0], [0.5, 0, 0], "-", "green")
        self.drawLine3D([-0.5, 0, 0.5], [0.5, 0, 0.5], "-", "green")

        self.drawLine3D([1, 1, 0], [1, 1, 1], "-", "green")
        self.drawLine3D([1, 1, 0], [-1, 1, 0], "-", "green")
        self.drawLine3D([-1, 1, 0], [-1, 1, 1], "-", "green")
        self.drawLine3D([-1, 1, 1], [1, 1, 1], "-", "green")

        self.drawText([0, -1, 0], "Camera")
        self.drawText([0.25, -0.5, 0], "Screen")
        self.drawText([0.5, 0, 0], "front")
        self.drawText([1, 1, 0], "end")

        pass

    pass

if __name__ == '__main__':
    pi_div4 = pi / 4
    fig = figure()
    painter = Painter(fig)
    #x, y, z = painter.sphericalDemo()
    #painter.drawPointLabel(x, y, z)
    #painter.triangleDemo()
    painter.cicleDemo()

    painter.show()
    pass