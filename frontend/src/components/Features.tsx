function Features() {
  const features = [
    {
      title: "Zero Trust Access",
      icon: "🛡️",
      description:
        "Verify every user, device, and request before granting access.",
    },
    {
      title: "AI Risk Engine",
      icon: "🤖",
      description:
        "Continuously analyze login behavior and detect suspicious activity.",
    },
    {
      title: "Live Monitoring",
      icon: "📊",
      description:
        "Track authentication events and security insights in real time.",
    },
  ];

  return (
    <section className="py-24 px-6 bg-slate-950">
      <div className="max-w-7xl mx-auto">
        <h2 className="text-4xl font-bold text-center">
          Why Choose <span className="text-cyan-400">Cyverra?</span>
        </h2>

        <p className="text-center text-gray-400 mt-4 max-w-2xl mx-auto">
          Secure your organization with AI-powered Zero Trust Identity &
          Access Management.
        </p>

        <div className="grid md:grid-cols-3 gap-8 mt-16">
          {features.map((feature) => (
            <div
              key={feature.title}
              className="bg-slate-900 rounded-2xl p-8 border border-slate-800 hover:border-cyan-400 transition duration-300 hover:-translate-y-2"
            >
              <div className="text-5xl">{feature.icon}</div>

              <h3 className="text-2xl font-semibold mt-6">
                {feature.title}
              </h3>

              <p className="text-gray-400 mt-4">
                {feature.description}
              </p>
            </div>
          ))}
        </div>
      </div>
    </section>
  );
}

export default Features;