try:
    import libparamEditor
except:
    print "Error: import of libparamEditor"

try:
    import libparamEditorDemo
except:
    print "Error: import of libparamEditorDemo"

old_libinit = libparamEditor.ConfItemBase.__init__
old_demoinit = libparamEditorDemo.Test1.__init__

def lib__init__(self):
    old_libinit(self)
    for ii in range(self.size()):
        setattr(self, "var%i" % ii, self.getChild(ii))


def demo__init__(self):
    old_demoinit(self)
    for ii in range(self.size()):
        setattr(self, "var%i" % ii, self.getChild(ii))

libparamEditor.ConfItemBase.__init__ = lib__init__
libparamEditorDemo.Test1.__init__ = demo__init__
