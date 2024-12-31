unt dec(unt* f, unt s, unt c) {
	return spaced_bits(rot_ca_set(f, s, c));
}
unt enc(unt* f, unt s, unt p) {
	unt c;
	for (size_t i = 0; i < A; i++) {
		c = ((unt) arc4random() << 32) | ((unt) arc4random());
		if (dec(f, s, c) == p) return c;
	}
	return 0;

}
