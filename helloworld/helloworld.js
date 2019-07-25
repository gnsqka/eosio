function name(a) {
    if(typeof a === 'number'){
        if(a < 0) a = -a;
        return a;

    }else {
        console.log('숫자입력');
        
    }
    
}