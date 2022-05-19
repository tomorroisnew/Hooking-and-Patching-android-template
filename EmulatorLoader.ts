const itf = Module.findExportByName("libhoudini.so", "NativeBridgeItf");
console.log("itf Address: " + itf);
console.log("NativeBridgeCallbacks version: " + itf.add(0).readUInt())
var loadLibrary = itf.add(16).readPointer()
console.log("loadLibrary: " + loadLibrary);

var dlopen = new NativeFunction(loadLibrary, 'pointer', ['pointer', 'int'])

dlopen(Memory.allocUtf8String("/data/local/tmp/libyeet.so"), 1)
