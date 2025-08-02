from setuptools import setup, Extension
import pybind11
import os

this_dir = os.path.dirname(__file__)
ex9_3_dir = os.path.join(this_dir, "..", "ex9.3")

ext_modules = [
    Extension(
        "pipeline",
        [
            os.path.join(this_dir, "pipeline_bind.cc"),
            os.path.join(ex9_3_dir, "Pipeline.cc")
        ],
        include_dirs=[pybind11.get_include(), ex9_3_dir],
        language="c++"
    )
]

setup(
    name="pipeline",
    version="0.1",
    ext_modules=ext_modules
)
