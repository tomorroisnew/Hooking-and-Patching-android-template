var dlopena = Module.findExportByName(null, 'dlopen')
var dlerrora = Module.findExportByName(null, 'dlerror')

var dlopen = new NativeFunction(dlopena, 'pointer', ['pointer', 'int'])
var dlerror = new NativeFunction(dlerrora, 'pointer', [])

dlopen(Memory.allocUtf8String("/data/data/com.dts.freefireth/libyeet.so"), 2)
