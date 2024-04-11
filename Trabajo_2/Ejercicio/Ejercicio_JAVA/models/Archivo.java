package Trabajo_4.actividad.models;

public class Archivo {

        private String nombre;
        private String tipo;
        private String contenido;

        public Archivo(String nombre, String tipo, String contenido) {
            this.nombre = nombre;
            this.tipo = tipo;
            this.contenido = contenido;
        }

        public String getNombre() {
            return nombre;
        }

        public String getTipo() {
            return tipo;
        }

        public String getContenido() {
            return contenido;
        }


        public void setNombre(String nombre) {
            this.nombre = nombre;
        }

        public void setTipo(String tipo) {
            this.tipo = tipo;
        }

        public void setContenido(String contenido) {
            this.contenido = contenido;
        }

}
