const itf = Module.findExportByName("libhoudini.so", "NativeBridgeItf");
console.log("itf Address: " + itf);
console.log("NativeBridgeCallbacks version: " + itf.add(0).readUInt())
var loadLibrary = itf.add(Process.pointerSize*2).readPointer()
console.log("loadLibrary: " + loadLibrary);

var getTrampoline = itf.add(Process.pointerSize*3).readPointer()

var dlopen = new NativeFunction(loadLibrary, 'pointer', ['pointer', 'int'])
var dlsym = new NativeFunction(getTrampoline, 'pointer', ['pointer', 'pointer', 'void', 'pointer'])

dlopen(Memory.allocUtf8String("/data/local/tmp/libyeet.so"), 1)
