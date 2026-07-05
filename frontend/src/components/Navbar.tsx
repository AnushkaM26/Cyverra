function Navbar() {
  return (
    <nav className="flex items-center justify-between px-8 py-5 border-b border-slate-800">
      <h1 className="text-2xl font-bold text-cyan-400">
        CYVERRA
      </h1>

      <ul className="hidden md:flex gap-8 text-gray-300">
        <li className="hover:text-cyan-400 cursor-pointer">Features</li>
        <li className="hover:text-cyan-400 cursor-pointer">Solutions</li>
        <li className="hover:text-cyan-400 cursor-pointer">About</li>
        <li className="hover:text-cyan-400 cursor-pointer">Contact</li>
      </ul>

      <button className="bg-cyan-500 hover:bg-cyan-600 px-5 py-2 rounded-lg font-semibold transition">
        Get Started
      </button>
    </nav>
  );
}

export default Navbar;