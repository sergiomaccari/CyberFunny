#include "Obstaculo.h"
namespace CyberMetro {
    namespace Entidades {
        namespace Obstaculos
        {
            Obstaculo::Obstaculo(float xi, float yi) :
                Entidade(xi, yi),
                danoso(false)
            {
                this->x = xi;
                this->y = yi;

            }
            Obstaculo::~Obstaculo() {}

            json Obstaculo::salvarDataBuffer() const
            {
                json j = Entidade::salvarDataBuffer();
                j["danoso"] = this->danoso;
                return j;
            }

            void Obstaculo::carregarDeBuffer(const json& data)
            {
                Entidade::carregarDeBuffer(data);
                this->danoso = data.value("danoso", this->danoso);
            }

            bool Obstaculo::getDanoso() const
            {
                return danoso;
            }

        }
    }
}