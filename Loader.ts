function hook_library(){
    Java.perform(function() {
        const System = Java.use('java.lang.System');

        System.load("/data/local/tmp/libyeet.so");
    });
}

hook_library()