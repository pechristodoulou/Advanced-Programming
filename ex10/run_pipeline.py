import pipeline

p = pipeline.Pipeline(n_items=12, n_consumers=3, max_delay=700)
print("Running pipeline from Python...")
p.run()
print("Pipeline finished.")
