function Hero() {
  return (
    <section className="flex flex-col items-center justify-center text-center px-6 py-24">

      <span className="bg-cyan-500/20 text-cyan-400 px-4 py-2 rounded-full text-sm mb-6">
        AI Powered Cybersecurity Platform
      </span>

      <h1 className="text-5xl md:text-7xl font-extrabold leading-tight max-w-5xl">
        Zero Trust Identity
        <br />
        Access Management
      </h1>

      <p className="text-gray-400 text-lg mt-8 max-w-3xl">
        Secure identities using continuous authentication,
        AI-powered risk analysis, and Zero Trust architecture.
      </p>

      <div className="flex gap-4 mt-10 flex-wrap justify-center">
        <button className="bg-cyan-500 hover:bg-cyan-600 px-8 py-4 rounded-xl font-semibold transition">
          Get Started
        </button>

        <button className="border border-cyan-500 text-cyan-400 hover:bg-cyan-500 hover:text-white px-8 py-4 rounded-xl transition">
          View Demo
        </button>
      </div>

      <div className="flex gap-8 mt-12 text-gray-300 flex-wrap justify-center">
        <span>✔ AI Risk Detection</span>
        <span>✔ Zero Trust</span>
        <span>✔ Live Monitoring</span>
      </div>

    </section>
  );
}

export default Hero;