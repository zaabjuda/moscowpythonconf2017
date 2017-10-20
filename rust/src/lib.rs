#![feature(proc_macro)]

#[macro_use] extern crate pyo3;

use pyo3::prelude::*;
/// Module documentation string 1
#[py::modinit(_addList)]
fn init(py: Python, m: &PyModule) -> PyResult<()> {
    py_exception!(_addList, EmptyListError);
    py_exception!(_addList, ItemListError);

    /// Function documentation string
    #[pyfn(m, "run", args="*", kwargs="**")]
    fn run_fn(_py: Python, args: &PyTuple, kwargs: Option<&PyDict>) -> PyResult<()> {
        run(args, kwargs)
    }

    #[pyfn(m, "add", py_list="*")]
    fn add(_py: Python, py_list: &PyList) -> PyResult<i32> {
        match  py_list.len() {
            0 =>Err(EmptyListError::new("List is empty")),
            _ => {
                let mut sum : i32 = 0;
                for item in py_list.iter() {
                    let temp:i32 = match item.extract() {
                        Ok(v) => v,
                        Err(_) => {
                            let err_msg: String = format!("List item {} is not int", item);
                            return Err(ItemListError::new(err_msg))
                        }
                    };
                    sum += temp;
                }
                Ok(sum)
            }
        }
    }

    Ok(())
}

fn run(args: &PyTuple, kwargs: Option<&PyDict>) -> PyResult<()> {
    println!("Rust says: Hello Python!");
    for arg in args.iter() {
        println!("Rust got {}", arg);
    }
    match kwargs {
        Some(kwargs) => {
            for (key, val) in kwargs.iter() {
                println!("{} = {}", key, val);
            }
        }
        None => {
            println!("Now kwargs")
        }
    }
    Ok(())
}