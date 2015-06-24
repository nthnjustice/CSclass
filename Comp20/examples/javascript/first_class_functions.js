function map(fn, list) {
	for (i = 0; i < list.length; i++) {
		list[i] = fn(list[i]);
	}
}

list = [7, -2, 33, 11, 18, 28];
map( function(x) {return x * x;}, list );
map( console.log, list );
